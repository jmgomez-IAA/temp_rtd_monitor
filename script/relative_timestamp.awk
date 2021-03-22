#!/usr/bin/awk -f

BEGIN{
# timeStamp
temp = 1615994717-3  
}

{
# timeStamp
$1=$1" "$2
# Data Source
$2=substr($3,0,1)

# Remove the Sensor number and the non valid data
gsub(/2:\+/," ",$3);  
gsub(/C/," ",$3);

# Substitute  / for :
timeData= $1

gsub(/[-:]/," ",timeData)
$4 = mktime(timeData)
$5 = $4 - temp

print
}