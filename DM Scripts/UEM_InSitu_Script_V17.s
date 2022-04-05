/* 	Script to save a series of DM images from a live view window.
		This is located within the HandleDataValueChangedAction method
	Script written by Ben Miller, based on a script for saving the live view image by Bernhard Schaffer.
	Last Update Oct 2018 by Daniel Du, with additions from Spencer Reisbeck
*/

// UPDATE NOTES
	// UPDATED FOR UEM AUTOMATION INTERFACING WITH LABVIEW CODE
	// COMMUNICATION THROUGH PASSED TEXT FILES (ONE RECEIVED FROM DELAY STAGE SCRIPT FOR SAVING DATA, ONE PASSED TO DELAY STAGE TO NOTIFY OF IMAGE SAVING EVENT)
	// ALL OKDIALOGS HAVE BEEN CHANGED TO RESULT

// Template Class for tools attached to live displays (camera View)
Class CAutoActOnImageUpdate
{
	Number 			imgID
	Number			KeyListenerID
	Number			ListenerID
	Number 			skip, i, oldStepNumber, waitStep, firstImg
	String			Dir1, Dir2, filenameInput, TPath, TPathTF
	String 			dm3path, dm3FN
	String 			delayunits
	number 			stepnumber, delay, scannum
	number 			Lambda, RepRate, Power
	
	String			delayStr, scannumStr, LambdaStr, RepRateStr, PowerStr
	taggroup 		texttags
	
	Object Launch( object self, image Img )
	{
		Result("Script has initiated.\n");
		// Check image and remember it's id as member variable
		// ( Don't keep the image itself, as it would prevent the image
		//   being able to get out of scope as long as the listener is 
		//   registered. By keeping the ID only, you can always just 
		//   check if it is still available and react accordingly. )
		if ( !img.ImageIsValid() )
			Throw( "Invalid image. Can not attach listeners. " )
		
		imgID = img.ImageGetID()
		
		// ADDED INFORMATION FOR UEM AUTOMATION --> SPECIFYING COMMUNICATION TXT FILE WITH DELAY STAGE SCRIPT
						
		// initialization of the path to read the file locations and UEM data at current image
		Dir1 = "C:"
		filenameInput = "InputFileTest.txt"
		
		TPath = Dir1
		TPathTF = pathconcatenate(TPath, filenameInput)
		taggroup texttags = ReadInTextFilePath(TPathTF)
		taggroup MetaDataTags
		
		i = 0;
		oldStepNumber = -1;
		waitStep = 0;
		firstImg = 0;
		
		// END ADDED INFORMATION

		// Define the messages and the triggered methods.
		// Here we only use the "data_value_changed" event.
		string messagemap 
		messagemap		+= "data_value_changed" 	+ ":HandleDataValueChangedAction;"
		if ( "" == messagemap ) return self;
		
		string userMessage = "Added Image Listener to [" + img.ImageGetLabel() + "]"
		
		// Now register the listener with the image.
		// Keep the returned ID so that the listner can be unregisterd as well.
 		// If the image gets out of scope (i.e. is closed), the listener will
 		// also automatically unregister.
		ListenerID 	= img.ImageAddEventListener( self, messagemap )
		
		// Register KeyListener to provide mechanism to stop the script
		// Not that this is an event registered with the DISPLAY, so it can 
		// not be done on images alone, but only on images which have a display
		if ( 0 < img.ImageCountImageDisplays() )
		{
			imageDisplay disp = img.ImageGetImageDisplay(0)
			KeyListenerID = disp.ImageDisplayAddKeyHandler( self, "KeyListenAction" )
			userMessage += "\nPress <space> to stop.\n" 
		}
		
		// Inform the user on start
		Result( userMessage )
		return self
	}
	
	void HandleDataValueChangedAction(object self, number e_fl, Image img )
	{
		// Just for safety, check if the image which invoked the event (and is passed through)
		// is the same as the one this objects thinks it has registered.
		// Not strictly necessary in this script.
		if ( img.ImageGetID() != imgID ) return
		
		//Check the current time, and use this to determine the correct hour/min/sec/frame for the image frame
		//number TimeD=(gethighrestickcount()-TimeI)/PerSec	
		
		//Clone Image
		image cloneImg := img.ImageClone()
		i++
		Result("" + i + " Updates Since Last Save. \n"); // ADDED FOR TRACKING PURPOSES
			
		// ADDED INFORMATION FOR UEM AUTOMATION --> FILE PATH AND FILE NAMES ACQUIRED FROM TXT FILE SPECIFIED IN LAUNCH METHOD
		// ACQUISITION TIME, BINNING SPECIFIED IN IN-SITU MODE PANEL ON DM
			
		// THIS SCRIPT WILL RELY ON LABVIEW TO REMAKE THE FILE BEFORE INITIATING THIS SCRIPT EVERY SINGLE TIME A SCAN IS RUN

		taggroup texttags = ReadInTextFilePath(TPathTF)

		//this take the "texttags" taggroup and dissects it into entered data
		texttags.TagGroupGetTagAsString( "inputline 1", dm3path)
		dm3path = pathextractdirectory(dm3path, 0) // This is a funny line of code that chops off a filename extension 

		// This is necessary because the text importer script like to attach linebreaks into the imported text that ruin paths
		texttags.TagGroupGetTagAsString( "inputline 2", dm3FN)
		dm3FN = pathextractbasename(dm3FN, 0) //yet again chopping off a extension, this one only holds a basename instead of full path
		
		texttags.TagGroupGetTagAsString( "inputline 3", delayunits)
		delayunits = pathextractbasename(delayunits, 0) //yet again

		//extracts step number and delay
		
		texttags.TagGroupGetTagAsNumber( "inputline 7", stepnumber)
		texttags.TagGroupGetTagAsString( "inputline 8", delay)
		texttags.TagGroupGetTagAsNumber( "inputline 9", scannum)
		texttags.TagGroupGetTagAsString( "inputline 8", delayStr)
		texttags.TagGroupGetTagAsString( "inputline 9", scannumStr)
		
		if (stepnumber == 1)
		{
			firstImg = 1
		}
		
		//extracts Laser Parameters
		
		texttags.TagGroupGetTagAsNumber( "inputline 10", Lambda)
		texttags.TagGroupGetTagAsNumber( "inputline 11", RepRate)
		texttags.TagGroupGetTagAsNumber( "inputline 12", Power)
		texttags.TagGroupGetTagAsString( "inputline 10", LambdaStr)
		texttags.TagGroupGetTagAsString( "inputline 11", RepRateStr)
		texttags.TagGroupGetTagAsString( "inputline 12", PowerStr)
			
		// END ADDED INFORMATION
			
		if(stepnumber != oldStepNumber && waitStep == 1 && firstImg == 1) // CHECK TO SEE IF THE DELAY STAGE HAS MOVIED AND THE NEW POSITION IS REGISTERED PROPERLY
		{
		
			Result("New delay found. Saving image.\n");
			
			// UEM AUTOMATION SAVING DATA
				
			//Attach tags to taken image
			cloneImg.SetNumberNote("LaserParameter:Step Number" , stepnumber) 
			cloneImg.SetNumberNote("LaserParameter:Delay" , delay) 
			cloneImg.SetStringNote("LaserParameter:Delay Units" , delayunits) 
			cloneImg.SetNumberNote("LaserParameter:Wavelength" , Lambda)
			cloneImg.SetNumberNote("LaserParameter:Repitition Rate" , RepRate)
			cloneImg.SetNumberNote("LaserParameter:Laser Power" , Power)
			
			Result("the DM3 destination is " + DM3path + " with filename " +dm3FN + "\n")
			Result("this acquisition is for step number " + stepnumber + " at a delay of " + delay + " " + delayunits + "\n")
			
			//Save DM3 file in the approporate place
			string FilenameDM3Out = DM3FN + "_" + scannum + "_" + stepnumber  + "_" + delay + delayunits
			string FilenameTIFFOut = DM3FN + "_" + scannum + "_" + stepnumber  + "_" + delay + delayunits
			string TPathDM3Out = pathconcatenate (DM3Path, FileNameDM3out)
			string TPathTIFFOut = pathconcatenate  (DM3Path, FileNameTIFFout)
				
			// END ADDED INFORMATION
			
			// GATAN PROVIDED PATH CHECKER
			//Check whether the directory exists, and if not, create it
			if(!DoesDirectoryExist(dm3path))		CreateDirectory(dm3path)
				
			// EDITED GATAN CODE
			// Now save the cloneImg into IS Dataset
			Result(GetTime(1)+": Saving updated frame: " + TPathDM3Out )
			Try
			{
				cloneImg.SaveAsGatan(TPathDM3Out)
				// ADDED TIFF INFORMATION
				cloneImg.SaveAsTIFF(TPathTIFFOut)
				Result(" [OK]\n")
			}
			catch
			{
				Result(" [FAILED]\n")
				break;
			}
				
			oldStepNumber = stepnumber;
			waitStep = 0;
				
			i = 0;
		}
		else if(stepnumber != oldStepNumber && waitStep == 0 && firstImg == 1)
		{
			waitStep = 1;
			Result("Step updated, acquiring image before saving.\n");
		}
		else if(stepnumber != 0 && waitStep == 0 && firstImg == 0)
		{
			firstImg = 1;
			waitStep = 1;
			Result("Initial step acknowledged, proceeding to acquisition. \n");
		}
		else if(stepnumber != 0 && waitStep == 0 && firstImg == 0)
		{
			Result("Initial image skipping to allow delay stage setup. \n");
		}
		else
		{
			Result("Same step, waiting for delay update.\n");
		}

	}
	
	// Convenience KEYs
	/////////////////////////////////////////////////////////////////////////////
	// Here you can add all "display keys" you want.
	void UnregisterAll( object self )
	{
		image img := GetImageFromID(imgID)
		if ( img.ImageIsValid() )
		{
			Result("Deleting File: " + TPathTF + "\n");
			DeleteFile(TPathTF);
			Result("Resetting File: " + TPathTF + "\n");
			Number delayFile
			delayFile = CreateFileForWriting(TPathTF);
			WriteFile(delayFile, "TestPath\n");
			WriteFile(delayFile, "Test\n");
			WriteFile(delayFile, "ps\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			WriteFile(delayFile, "0\n");
			CloseFile(delayFile);
			img.ImageRemoveEventListener( ListenerID )
			if ( 0 < img.ImageCountImageDisplays() )
				img.ImagegetImageDisplay(0).ImageDisplayRemoveKeyHandler( KeyListenerID )
		}
		Result( "\n Stopped Image Listeners" )
	}
		
	Number 	KeyListenAction(Object self, ImageDisplay disp, Object keydesc ) 
	{
		number b_keyhandled = 0
		If ( keydesc.MatchesKeyDescriptor("space") ) 
		{
			Result("\n Script exit command pressed.");
			self.UnregisterAll()
			b_keyhandled = 1
		}
		return b_keyhandled;
	}
}

Alloc(CAutoActOnImageUpdate).Launch( GetFrontImage() )