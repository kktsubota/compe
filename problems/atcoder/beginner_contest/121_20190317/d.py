import numpy as np


def sum_to_num(num):
    if num == 0:
        return 0
    
    elif num == 1:
        return 1
    elif num == 2:
        return 3
    elif num == 3:
        return 0

    base = 2 ** (len('{:b}'.format(num)) - 1)

    if num % 2 == 0:
        return sum_to_num(num - base) + base
    else:
        return sum_to_num(num - base)

A, B = map(int, input().split())
if A == 0:
    print(sum_to_num(B))
else:
    print(np.bitwise_xor(sum_to_num(B), sum_to_num(A - 1)))



# def to_vector(binary, length=None):
#     if length is None:
#         length = len(binary)
    
#     vector = np.zeros(length, dtype=bool)
#     offset = length - len(binary)
#     for i in range(offset, length):
#         vector[i] = bool(int(binary[i - offset]))
#     return vector

# def from_vector(vector):
#     vec_s = map(str, vector.astype(int).tolist())
#     binary = ''.join(list(vec_s))
#     return binary

# A, B = map(int, input().split())
# # A_bin = '{:b}'.format(A)
# # B_bin = '{:b}'.format(B)
# # length = max(len(A_bin), len(B_bin))
# # A_vec = to_vector(A_bin, length)
# # B_vec = to_vector(B_bin, length)
# # ans = np.logical_xor(A_vec, B_vec)
# # binary = from_vector(ans)
# # print(eval('0b' + binary))
# print(np.bitwise_xor(A, B))