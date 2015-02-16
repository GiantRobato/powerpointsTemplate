(set -o igncr) 2>/dev/null && set -o igncr; # this comment is needed

#Black        0;30     Dark Gray     1;30
#Blue         0;34     Light Blue    1;34
#Green        0;32     Light Green   1;32
#Cyan         0;36     Light Cyan    1;36
#Red          0;31     Light Red     1;31
#Purple       0;35     Light Purple  1;35
#Brown/Orange 0;33     Yellow        1;33
#Light Gray   0;37     White         1;37


#TODO: add add BG and FG colors
Green='\033[0;32m'
Red='\033[0;31m'
Black='\033[30m'
NC='\033[0m' # No Color
GreenBG='\033[0;42m'
RedBG='\033[0;41m'

#checking for arguments
while [ "$1" != "" ]; do
	case $1 in
		-h | --help )		echo "This file checks the output of TestingFileIO.exe"
							echo "Use -l | --list to show the list of testCases and descriptions"
							;;
		-l | --list ) 		echo "testCase 1 - expected output is: 'Writing this to file.'"
							listing=1
							;;
	esac
    # Shift all the parameters down by one
    shift

done


#testCases, send anything weird to log
./testFileIO.exe &>testCase1.log 
mv testCase1.log ../log

echo

echo "Testing FileIO"
echo 

#compare the output found to our expected
#if -l was set, print expected
if cmp -s example.txt ../tests/example.expected > /dev/null ; then
	echo -e "testCase 1   ---------------------------------------------------------\033[30m\033[42m  PASS  \033[0m"
else
	if [ "$listing" -eq "1"]
	then
		echo "testCase 1 - expected output is: 'Writing this to file.'"
	fi
	echo -e "testCase 1   ---------------------------------------------------------"${RedBG}"  FAIL  "${NC}
fi
#echo -e "${Green}Log file is located in log/testCase#.log${NC}"
#cat ../log/testCase1.log
