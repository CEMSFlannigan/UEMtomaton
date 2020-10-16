// $BACKGROUND$

// test_2.s
// 2016-01-06 
// E James

// Script to demonstarte low dose mode
// Grab and display image based on user input
// 1. bin mode
// 2. frame exposure time
// 3. number of frames

//	OneView read modes
number BALTORO_READ_MODE_CDS = 0;
number BALTORO_READ_MODE_CDS_DIFF = 1;
number BALTORO_READ_MODE_IMG = 2;
number BALTORO_READ_MODE_IMG_DIFF = 3;
number BALTORO_READ_MODE_RST = 4;

// SW processing modes
number SW_PROCESSING_UNPROCESSED = 1;
number SW_PROCESSING_DARK_SUBTRACTION = 2;
number SW_PROCESSING_GAIN_NORMALIZED = 3;

// exposure priority
number EXPOSURE_PRIORITY_FRAME = 0;
number EXPOSURE_PRIORITY_TOTAL = 1;

// Shutter modes
number SHUTTER_MODE_OPEN = 0;
number SHUTTER_MODE_CLOSED = 1;



number STACK_ACQUIRE_DISABLED = 0;
number STACK_ACQUIRE_ENABLED = 1;

// stack format
number STACK_SERIES = 0;
number STACK_SUMMED = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ACQUISITION PARAMETERS
/////////////////////////////////////////////////////////////////////////////////////////////////////////

number baltoro_readmode = BALTORO_READ_MODE_CDS;	
number shutter_mode = SHUTTER_MODE_CLOSED;
number stack_acquire = STACK_ACQUIRE_ENABLED;
number stack_format = STACK_SUMMED;
number exp_priority = EXPOSURE_PRIORITY_FRAME; // FRAME or TOTAL

image DoAcquireSimple(number exp, number nr_frames, number sw_processing, number bin, number shutter)
{

	number frame_exposure = exp;
	number exposure = frame_exposure * nr_frames;
		
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SETUP AQUISITION
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	object camera = cm_getcurrentcamera();
	object acq_params;
	Number ccd_full_width, ccd_full_height;
	

	acq_params = camera.CM_GetCameraAcquisitionParameterSet("Imaging", "Acquire", "Record", 1)

	camera.CM_CCD_GetSize(ccd_full_width, ccd_full_height);
	acq_params.cm_setccdreadarea(0, 0, ccd_full_height, ccd_full_width);
	acq_params.CM_SetProcessing(sw_processing); 
	acq_params.CM_SetShutterExposure(shutter_mode);
	acq_params.CM_SetReadMode(baltoro_readmode);
	acq_params.CM_SetDoAcquireStack(stack_acquire); 
	acq_params.CM_SetStackFormat(stack_format);
	acq_params.CM_SetExposurePrecedence(exp_priority); 
	acq_params.CM_SetExposure(exposure);
	acq_params.CM_SetFrameExposure(frame_exposure);

	acq_params.CM_SetBinning(bin, bin);

	image sumImage, stackImage;
	
	if(shutter)
	{
		CM_SetShutterExposure(acq_params, 1)	
	}
	else
	{
		CM_SetShutterExposure(acq_params, 0)
	}
	CM_Validate_AcquisitionParameters( camera, acq_params );		
	sumImage := cm_acquireimage(camera, acq_params);
	CM_WriteAcquisitionTagsToImage( sumImage, camera, acq_params )
	
	number xs, ys
	Getsize(sumImage, xs, ys)

	image img = realimage("", 4, xs, ys)

	img += sumimage
	
	CM_WriteAcquisitionTagsToImage( img, camera, acq_params )
	
	//showimage(img)
	//showimage(sumImage)
	
	return(img)
}


// **********
// ** MAIN **
// **********

number binMode, frameTime, frameNum, frameOK = 0, binOK = 0, frameNumOK = 0

while(binOK == 0)
{
	If(!GetNumber("Bin mode ? 1, 2 or 4", binMode, binMode))
	If(binMode == 1) binOK = 1
	If(binMode == 1) binOK = 1
	If(binMode == 2) binOK = 1
	If(binMode == 4) binOK = 1
}

while(frameOK == 0)
{
	If(!GetNumber("Frame exposure (in s) 0.1 to 120", frameTime, frameTime))
	If(frameTime <= 120) frameOK = 1
	If(frameTime <= 120) frameOK = 1
	If(frameTime < 0.1) frameOK = 0
}

while(frameNumOK == 0)
{
	If(!GetNumber("Number of frames 1 to 100", frameNum, frameNum))
	If(frameNum <= 100) frameNumOK = 1
	If(frameNum <= 100) frameNumOK = 1
	If(frameNum < 1) frameNumOK = 0
}
frameNum = round(frameNum)

result("Grab with bin = "+binMode+"\tframe exp = "+frameTime+"\tNumber of frames = "+frameNum+"\ttot exp = "+(frameTime*frameNum)+"\n")

showImage(DoAcquireSimple(frameTime, frameNum, SW_PROCESSING_GAIN_NORMALIZED, binMode, 0))


