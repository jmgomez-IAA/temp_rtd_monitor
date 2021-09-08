import csv
from datetime import datetime, timedelta

with open('../data/lakeshore_pt1000_ref_ads1248_filter.dat', 'r') as csvfile:
    reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in reader:        
    
        end_day = row[0]
        end_time = row[2]
        # Create a datetime object
        dt_end = datetime.strptime(end_day + ' ' + end_time, "%m/%d/%y %H:%M:%S")

        # Translate duration into minutes
        #duration=float(row[2])*60

        # Calculate start time
        #start = dt_end - timedelta(minutes=duration)

        # Column 3 is the start day (can differ from end day!)
        row.append(dt_end.isoformat())
        # Column 4 is the start time
        #row.append(start.strftime("%H%M"))

        print (' '.join(row))