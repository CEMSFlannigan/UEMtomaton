/* 	Script to save a series of DM images from a live view window.
		This is located within the HandleDataValueChangedAction method
	Script written by Ben Miller, based on a script for saving the live view image by Bernhard Schaffer.
	Last Update Oct 2018 by Daniel Du, with additions from Spencer Reisbeck
*/

// UPDATE NOTES
	// UPDATED FOR UEM AUTOMATION INTERFACING WITH LABVIEW CODE
	// COMMUNICATION THROUGH PASSED TEXT FILES (ONE RECEIVED FROM DELAY STAGE SCRIPT FOR SAVING DATA, ONE PASSED TO DELAY STAGE TO NOTIFY OF IMAGE SAVING EVENT)
	// ALL OKDIALOGS HAVE BEEN CHANGED TO RESULT


image	FirstImg, diffImg

// Template Class for tools attached to live displays (camera View)
Class CAutoActOnImageUpdate
{
	Number 			imgID, diffID
	Number			KeyListenerID
	Number			ListenerID
	Number			trackFirst
	imagedisplay	diffdisp
	
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
		trackFirst = 0;

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
		
		if ( trackFirst == 0 )
		{
			trackFirst = 1;
			FirstImg := img.ImageClone()
		}
		
		//Clone Image
		image cloneImg := img.ImageClone()
		
		image diffImg = cloneImg - FirstImg
		
		showimage(diffImg)
		string imgname=getname(img)
		setname(diffImg, "Live difference of "+imgname)
		
		imageDisplay diffDisp = img.ImageGetImageDisplay(0)
		DiffKeyListenerID = diffDisp.ImageDisplayAddKeyHandler( self, "KeyListenAction" )
		
		return self
	}
	
	void HandleDataValueChangedAction(object self, number e_fl, Image img )
	{
		//Check the current time, and use this to determine the correct hour/min/sec/frame for the image frame
		//number TimeD=(gethighrestickcount()-TimeI)/PerSec	
		
		//Clone Image
		image cloneImg := img.ImageClone()
		
		image diffImg = cloneImg - FirstImg
		
		showimage(diffImg)
		string imgname=getname(img)
		setname(diffImg, "Live difference of "+imgname)

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
			{
				img.ImagegetImageDisplay(0).ImageDisplayRemoveKeyHandler( KeyListenerID )
				//diffImg.ImageGetImageDisplay(0).ImageDisplayRemoveKeyhandler( DiffKeyListenerID )
			}
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