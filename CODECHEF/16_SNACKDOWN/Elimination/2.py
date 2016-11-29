def main():
	t = int(input())
	for ite in range(t):
		x = raw_input()
		n = int(x.split(" ")[0])
		total  = int(x.split(" ")[1])
		if (2*total)%n is not 0:
			print "No"
			continue
		temp = total/n
		check = 0
		if (n%2) is 1:
			if temp > (n-1)/2:
				check = 1
		else:
			if temp > n-1:
				check = 1
			temp1 = (2*total)/n
			k = n/2
			if temp1 >= 4*k:
				check = 1
			if ((temp1 > 2*k) and (temp1%2 is 1)):
				check = 1 

		if check is 1:
			print "Yes"
		else:
			print "No"


main()