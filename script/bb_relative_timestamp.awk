#!/usr/bin/awk -f

BEGIN{
# timeStamp
temp = 1615478459  
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
timeData = sprintf("20%s %s %s %s %s %s", substr($1,7,2), substr($1,4,2), substr($1,1,2), substr($1,10,2), substr($1,13,2), substr($1,16,2))

$1=sprintf("20%s-%s-%s %s:%s:%s", substr($1,7,2), substr($1,4,2), substr($1,1,2), substr($1,10,2), substr($1,13,2), substr($1,16,2))


$4 = mktime(timeData)
$5 = $4 - temp

print
}