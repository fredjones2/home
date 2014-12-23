fees=20
number1=int(raw_input("how much is your stock "))
number2=int(raw_input("how many shares do you want to buy "))
result=number2 * number1
print "that's %r bones" % (result)

dividend=float(raw_input("how much dividend? "))
earned=number2 * dividend
earned_year= number2 * dividend * 4
print "your dividend is %r per quarter" % (earned)
print "your dividend is %r per year" % (earned_year)

total_investment=fees + result
print "you are in for %r dollars including fees" % (total_investment)

minimum_sale=int(raw_input("what's the stock price?"))
diff= (minimum_sale * number2) - total_investment
if diff < 0:
    print "loser"
    print diff
else:
    print "winner"
    print diff
