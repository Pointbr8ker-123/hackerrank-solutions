def is_leap(year):
    leap = False
    
    # Write your logic here
    if year % 4 != 0: # i.e year % 4 == 0 is leap year
        return leap
    elif year % 100 != 0:
        leap = True # year % 4 == 0 and year % 100 != 0 is leap year
    elif year % 400 == 0:
        leap = True # year % 4 == 0 and year % 100 == 0 but also year % 400 == 0... therefore is leap year
    
    
    return leap

year = int(input())
print(is_leap(year))