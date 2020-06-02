A = [0, 1, 1]

answers = list()
for i in range(len(A)):
    if i == 0:
        ans = A[0] % 5
    
    else:
        ans = (ans * 2 + A[i]) % 5
    answers.append(ans == 0)
    # binary = ''.join(map(str, A[0:i+1]))
    # ans.append(int(binary, 2) % 5)

print(answers)

#     ans.append(bin_list_to_int5(A[0:i+1]) % 5)

# def bin_list_to_int5(bin_list):
#     ans = 0
#     for i, bin_ in enumerate(bin_list):
#         if bin_ == 1:
#             ans = 2 ** (len(bin_list) - i - 1)
#             ans = ans % 5
    
#     return ans
