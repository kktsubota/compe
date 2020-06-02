def print_arr(arr):
    for row in arr:
        print(''.join(map(str, row)))


def main():
    H, W, A, B = map(int, input().split())
    # shape (H, W)
    arr = [[0] * W for i in range(H)]
    if A == 0 and W == 1:
        for i in range(B):
            arr[i][0] = 1
        print_arr(arr)
        return

    if B == 0 and H == 1:
        for j in range(A):
            arr[0][j] = 1
        print_arr(arr)
        return
        
    if H == W and A == B:
        for i in range(H):
            for j in range(A):
                arr[i][(i + j) % W] = 1
        print_arr(arr)
        return
    
    if H > W and H % W == 0 and W * B == H * A:
        for j in range(W):
            for i in range(B):
                arr[(i + B * j) % H][j] = 1
        print_arr(arr)
        return

    if W > H and W % H == 0 and W * B == H * A:
        for i in range(H):
            for j in range(A):
                arr[i][(A * i + j) % W] = 1
        print_arr(arr)
        return

    print('No')
    return
    

if __name__ == "__main__":
    main()
