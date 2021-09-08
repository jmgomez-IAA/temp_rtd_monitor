#!/bin/bash

# Convert output from lakeshore to aceptable data for excel.
# Add a Column with the timestamp in since epoc.
echo
if [ "$1" == "" ]  #if parameter not exists error, requires DATA FILE
   then  echo "USAGE ${0} input_filename.dat output_filename.csv"
   exit
   fi

echo 
if [ "$2" = "" ]  #if parameter not exists error, requires REPO_NAME
   then  echo "USAGE ${0} input_filename.dat output_filename.csv"
	exit
   fi

DAT_FILE=$1
WORK_FILE=${DAT_FILE}.temp
CSV_FILE=$2

if [ -f $DAT_FILE ]; then
	tr -d '\r' < ${DAT_FILE}  > ${WORK_FILE}
else
	echo "Error: Input file does not exist"
	exit
fi

# Create a backup of the input file.
#dos2unix $1_w
sed 'N;s/\n/ /g;  s/ \+/ /g; s/[[:digit:]]:+/\t/g;s/C //g;s/\ \ */\ /g' ${WORK_FILE} > ${CSV_FILE}

rm -f ${WORK_FILE}
awk 'BEGIN{FS="\t"; OFS="\t"}
{
	$10=$9;$9=$8;$8=$7;$7=$6;$6=$5;$5=$4;$4=$3;$3=$2;
	$1=sprintf("20%s-%s-%s %s:%s:%s", substr($1,7,2), substr($1,1,2), substr($1,4,2), substr($1,10,2), substr($1,13,2), substr($1,16,2))
    timestamp = $1
	gsub(/[-:]/," ",timestamp)
	$2 = mktime(timestamp)
	
	print
}' ${CSV_FILE} > ${WORK_FILE}
rm -f ${CSV_FILE}
mv ${WORK_FILE} ${CSV_FILE}

sed -i '1i Fecha\tTimestamp\tCh1\tCh2\tCh3\tCh4\tCh5\tCh6\tCh7\tCh8' ${CSV_FILE} 
echo "${CSV_FILE} created."

# Cleaning

# Remove temporal Working file
rm -f ${WORK_FILE}