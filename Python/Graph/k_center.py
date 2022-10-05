# Python3 program for the above approach
def maxindex(dist, n):
	mi = 0
	for i in range(n):
		if (dist[i] > dist[mi]):
			mi = i
	return mi

def selectKcities(n, weights, k):
	dist = [0]*n
	centers = []

	for i in range(n):
		dist[i] = 10**9
		
	# index of city having the
	# maximum distance to it's
	# closest center
	max = 0
	for i in range(k):
		centers.append(max)
		for j in range(n):

			# updating the distance
			# of the cities to their
			# closest centers
			dist[j] = min(dist[j], weights[max][j])

		# updating the index of the
		# city with the maximum
		# distance to it's closest center
		max = maxindex(dist, n)

	# Printing the maximum distance
	# of a city to a center
	# that is our answer
	# print()
	print(dist[max])

	# Printing the cities that
	# were chosen to be made
	# centers
	for i in centers:
		print(i, end = " ")

# Driver Code
if __name__ == '__main__':
	n = 4
	weights = [ [ 0, 4, 8, 5 ],
			[ 4, 0, 10, 7 ],
			[ 8, 10, 0, 9 ],
			[ 5, 7, 9, 0 ] ]
	k = 2

	# Function Call
	selectKcities(n, weights, k)

# This code is contributed by mohit kumar 29.
