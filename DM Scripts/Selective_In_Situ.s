/* 	Script to save a series of DM images from a live view window.
		The 'Skip' parameter controls whether every frame is captured. 
		This is located within the HandleDataValueChangedAction method
	Script written by Ben Miller, based on a script for saving the live view image by Bernhard Schaffer.
	Last Update Aug 2018
*/

// Function to produce a filename compatible with Gatan's IS Player
string CreateISFileName(string DirName, string FileName, number hour, number minute, number second, number frame)
	{
	string ISFileName=FileName+"_"+frame+".dm4"
		   ISFileName=PathConcatenate(DirName,ISFileName)
	return ISFileName
	}
	
// Template Class for tools attached to live displays (camera View)
Class CAutoActOnImageUpdate
{
	Number 			imgID
	Number			KeyListenerID
	Number			ListenerID
	String			SavePath, SaveBaseName 
	Number 			TimenumberO, Frame, PerSec, TimeI, skip, totalSaves, numSaved
	Number 			year, month, day, hr, min, sec, nsec, i
	
	Number 			oldStepNumber, waitStep, firstImg
	String			Dir1, Dir2, filenameInput, TPath, TPathTF
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
		Dir1 = "X:"
		Dir2 = "TestFile"
		filenameInput = "SIIFileInput.txt"
		
		TPath = pathconcatenate(Dir1, Dir2)
		TPathTF = pathconcatenate(TPath, filenameInput)
		taggroup texttags = ReadInTextFilePath(TPathTF)
		taggroup MetaDataTags

		//this take the "texttags" taggroup and dissects it into entered data
		texttags.TagGroupGetTagAsString( "inputline 1", SavePath)
		SavePath = pathextractdirectory(SavePath, 0) // This is a funny line of code that chops off a filename extension 

		// This is necessary because the text importer script like to attach linebreaks into the imported text that ruin paths
		texttags.TagGroupGetTagAsString( "inputline 2", SaveBaseName)
		SaveBaseName = pathextractbasename(SaveBaseName, 0) //yet again chopping off a extension, this one only holds a basename instead of full path
		
		texttags.TagGroupGetTagAsNumber( "inputline 4", skip)
		texttags.TagGroupGetTagAsNumber( "inputline 5", totalSaves)
		
		result("Save Path: " + SavePath + "\n")
		result("Save Base: " + SaveBaseName + "\n")
		result("Images to Skip: " + skip + "\n")
		result("Total Saves: " + totalSaves + "\n")
		
		skip++;
		numSaved = 0;
		Frame = 0;

		//Get year, month, day
		DeconstructLocalGregorianDate(getcurrenttime(), year, month, day, hr, min, sec, nsec)

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
		
		image cloneImg := img.ImageClone()
		string FileName=CreateISFileName(SavePath, SaveBaseName, hr, min, sec, Frame)
		cloneImg.SaveAsGatan( FileName )
					Result( "Saved initial image.\n")
		
		// Register KeyListener to provide mechanism to stop the script
		// Not that this is an event registered with the DISPLAY, so it can 
		// not be done on images alone, but only on images which have a display
		if ( 0 < img.ImageCountImageDisplays() )
		{
			imageDisplay disp = img.ImageGetImageDisplay(0)
			KeyListenerID = disp.ImageDisplayAddKeyHandler( self, "KeyListenAction" )
			userMessage += "\nPress <SPACE> to stop.\n" 
		}
		
		// Inform the user on start
		Result( userMessage )
		return self
	}
	
	void HandleDataValueChangedAction(object self, number e_fl, Image img )
	{
		//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
		//Only save 1 of every 'skip' frames
		//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX		
		
		// Just for safety, check if the image which invoked the event (and is passed through)
		// is the same as the one this objects thinks it has registered.
		// Not strictly necessqary in this script.
		if ( img.ImageGetID() != imgID ) return
		
		//Check the current time, and use this to determine the correct hour/min/sec/frame for the image frame
		number TimeD=(gethighrestickcount()-TimeI)/PerSec	
		//Clone Image
		image cloneImg := img.ImageClone()
			i++
		
		if (totalSaves != -1)
		{
			if((mod(i,skip)==0 || skip == 0) && numSaved <= totalSaves)
			{
				Frame=Frame+1
				//Add tag to cloned image with elapsed time in seconds
				taggroup ImgTG=imagegettaggroup(cloneImg)
				ImgTG.TagGroupSetTagAsString("DataBar:Elapsed time (s)", format(TimeD,"%5.3f") )
				
				DeconstructLocalGregorianDate(getcurrenttime(), year, month, day, hr, min, sec, nsec)
				
				//Use function defined above to create the proper filename string
				string FileName=CreateISFileName(SavePath, SaveBaseName, hr, min, sec, Frame)
						
				//Check whether the directory exists, and if not, create it
				string ISFilePath=PathExtractDirectory(FileName,0)
						if(!DoesDirectoryExist(ISFilePath))		CreateDirectory(ISFilePath)
				// Now save the cloneImg into IS Dataset
				Result(GetTime(1)+": Saving updated frame: " + fileName + "\n")
				Try
				{
					cloneImg.SaveAsGatan( fileName )
					Result( "Saved image.\n")
				}
				catch
				{
					Result( "Failed to save image.\n")
					break;
				}
				numSaved++;
			}
		}
		else
		{
			if(mod(i,skip)==0 || skip == 0)
			{
				Frame=Frame+1
				//Add tag to cloned image with elapsed time in seconds
				taggroup ImgTG=imagegettaggroup(cloneImg)
				ImgTG.TagGroupSetTagAsString("DataBar:Elapsed time (s)", format(TimeD,"%5.3f") )
				
				DeconstructLocalGregorianDate(getcurrenttime(), year, month, day, hr, min, sec, nsec)
				
				//Use function defined above to create the proper filename string
				string FileName=CreateISFileName(SavePath, SaveBaseName, hr, min, sec, Frame)
						
				//Check whether the directory exists, and if not, create it
				string ISFilePath=PathExtractDirectory(FileName,0)
						if(!DoesDirectoryExist(ISFilePath))		CreateDirectory(ISFilePath)
				// Now save the cloneImg into IS Dataset
				Result(GetTime(1)+": Saving updated frame: " + fileName + "\n")
				Try
				{
					cloneImg.SaveAsGatan( fileName )
					Result( "Saved image.\n")
				}
				catch
				{
					Result( "Failed to save image.\n")
					break;
				}
			}
		}
		
		// END FUNCTION

	}
	
	// Convenience KEYs
	/////////////////////////////////////////////////////////////////////////////
	// Here you can add all "display keys" you want.
	void UnregisterAll( object self )
	{
		image img := GetImageFromID(imgID)
		if ( img.ImageIsValid() )
		{
			img.ImageRemoveEventListener( ListenerID )
			if ( 0 < img.ImageCountImageDisplays() )
				img.ImagegetImageDisplay(0).ImageDisplayRemoveKeyHandler( KeyListenerID )
		}
		OKDialog( "Stopped Image Listeners" )
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