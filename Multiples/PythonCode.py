import re
import string

#Square the number sent from c++ assigned to num
def SquareValue(num):

    #Print the number being squared
    print("\n", num, " * ", num, " = ", num * num, "\n")

    return

#Create a times table using the number sent from c++ 
def TimesTable(num):

    #Initial loop number
    i = 1

    print("\n Displaying the times table... \n")

    #Loop from 1-10
    while i <= 10:

        #Print the times table
        print(num, " * ", i, " = ", num * i)
        i = i + 1

    return



