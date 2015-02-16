(set -o igncr) 2>/dev/null && set -o igncr; # this comment is needed

echo "making webpage"

DIR=${PWD##*/}          # to assign to a variable

#must change the directory since the program is relative to project directory

if [ "$DIR" = "bin" ] ; then
	echo "Already in bin directory"
else
	cd bin						#change directory so we can run this from project
								#directory	
	echo "Changing to Bin Directory"
fi

./testWriteHTML.exe
mv testWriteHTML.html ..