def is_grand_festival(year):
    # Your logic here
    if year % 10 != 0:
        return False # i.e year % 10 == 0 is festival
    elif year % 50 != 0:
        return True # i.e year % 10 == 0 and year % 50 != 0 is festival
    elif year % 200 == 0:
        return True # i.e year % 10 == 0 and year + 50 == 0 but also, year % 200 == 0, making it festival year
    else:
        return False
    

# Sample test
year = int(input())
print(is_grand_festival(year))
