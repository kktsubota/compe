s = input()
if s[0::2].lower() == s[0::2] and s[1::2].upper() == s[1::2]:
    print("Yes")
else:
    print("No")
    