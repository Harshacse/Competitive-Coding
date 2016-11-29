def print_all(string,sort_string,result):
	if string == "":
		print result
		return
	i=0
	j=-1
	print_all(string[j+1:],sort_string,result)
	while i<len(sort_string):
		j = string.find(sort_string[i])
		if j!=-1:
			result += sort_string[i]
			print_all(string[j+1:],sort_string,result)
		i+=1
		

def main():
	t = int(input())
	for t_ in range(t):
		string = raw_input()
		sort_string = ''.join(sorted(set(string)))
		for i in range(len(sort_string)):
			result = sort_string[i]
			j = string.find(sort_string[i])
			print_all(string[j+1:],sort_string,result)
main()
