def main():
	t = int(input())
	for ite in range(t):
		x = raw_input()
		R = int(x.split(" ")[0])
		C = int(x.split(" ")[1])
		M = int(x.split(" ")[2])
		K = int(x.split(" ")[3])
		J = int(x.split(" ")[4])
		# print M+K+J,R*C
		if M+K+J != R*C:
			print "No"
			continue
		temp = []
		temp.append(M)
		temp.append(K)
		temp.append(J)
		check = 0
		# print temp
		for i in range(3):
			if temp[i]%R is 0:
				x = temp[i]/R
				if (temp[(i+1)%3]%R is 0) and (temp[(i+2)%3]%R is 0): 
					check = 1
				if (temp[(i+1)%3]%(C-x) is 0) and (temp[(i+2)%3]%(C-x) is 0):
					check = 1
			if temp[i]%C is 0:
				x = temp[i]/C
				if (temp[(i+1)%3]%C is 0) and (temp[(i+2)%3]%C is 0): 
					check = 1
				if (temp[(i+1)%3]%(R-x) is 0) and (temp[(i+2)%3]%(R-x) is 0):
					check = 1
		if check == 1:
			print "Yes"
		else:
			print "No"

main()