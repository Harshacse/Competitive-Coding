def main():
	t = int(input())
	for i in range(t):
		x = raw_input()
		N = int(x.split(" ")[0])
		K = int(x.split(" ")[1])
		E = int(x.split(" ")[2])
		M = int(x.split(" ")[3])
		input_sum = []
		for j in range(N-1):
			x = raw_input()
			temp = 0
			temp_lis = x.split(" ")
			for k in range(E):
				temp += int(temp_lis[k])
			input_sum.append(temp)
		required_sum = 0
		x = raw_input()
		temp_lis = x.split(" ")
		for j in range(E-1):
			required_sum += int(temp_lis[j])
		count = 0
		input_sum.sort()
		j = N-K-1
		answer = input_sum[j]-required_sum+1
		if answer>M:
			print "Impossible"
		elif answer<0:
			print 0
		else:
			print answer
main()