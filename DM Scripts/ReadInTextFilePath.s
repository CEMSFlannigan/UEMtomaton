taggroup ReadInTextFilePath ( string path)
{
//this is a program that 
number filereference
string thisline
number counter = 1
number spacing

string directory = pathextractdirectory(path , 0)
string extension = pathextractextension(path , 0)

//result (path)

if ( extension != "txt")
	{
		result (extension)
		ShowAlert("The Selected file is not a text file (.txt)" , 2)
		exit(0)
	}

//try/catch to open the file for reading but close it in case of error

try
	{
		filereference = openfileforreading(path)
		number readok = 1
		string test
		
		while(readok==1)
			{
			readok = filereference.readfileline(1,thisline)
				//while( file_stream.StreamReadTextLine(0,0,text) ) Result(text)
				//Result(thisline)
				if (counter<=3)
					{
					SetPersistentStringNote("temp tags:inputline "+counter, thisline)
					}
					else
					{
					SetPersistentNumberNote("temp tags:inputline "+counter, val(thisline))
					}	
				counter++
			}
	}
catch //there was an error, close the file
	{
		closefile(filereference)
		showalert("sorry, there was an error" , 2)
		exit(0)
	}
closefile(filereference)

taggroup ptags = getpersistenttaggroup()
taggroup temptags
ptags.taggroupgettagastaggroup("temp tags", temptags)
return temptags
}
