import numpy as np
from itertools import permutations
def nearest_neighbor(matrix):
    n = matrix.shape[0]
    current_city = np.random.randint(n)
    visited_cities = [current_city]
    total_distance = 0
    while len(visited_cities) < n:
        nearest_city = np.argmin([matrix[current_city][i] for i in range(n) if i not in visited_cities])
        visited_cities.append(nearest_city)
        total_distance += matrix[current_city][nearest_city]
        current_city = nearest_city
    total_distance += matrix[visited_cities[-1]][visited_cities[0]]
    visited_cities.append(visited_cities[0])
    return visited_cities, total_distance
def calculate_distance_matrix(points):
    n = len(points)
    dist_matrix = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            dist_matrix[i][j] = np.sqrt((points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2)
    return dist_matrix
points = [(0, 0), (1, 2), (3, 1), (2, 3)]
matrix = calculate_distance_matrix(points)
route, approx_distance = nearest_neighbor(matrix)
perm = permutations(range(len(points)))
optimal_distance = float('inf')
for p in perm:
    distance = 0
    for i in range(len(p) - 1):
        distance += matrix[p[i]][p[i + 1]]
    distance += matrix[p[-1]][p[0]]
    if distance < optimal_distance:
        optimal_distance = distance
print("Points:", points)
print("Approximation Route:", route)
print("Approximation Distance:", approx_distance)
print("Optimal Distance:", optimal_distance)
print("Error Approximation:", (approx_distance - optimal_distance) / optimal_distance)
