
def main():
    s1 = input()
    s2 = input()
    if s1 == "##" or s2 == "##":
        return True
    
    elif s1[0] == "#" and s2[0] == "#":
        return True
    
    elif s1[1] == "#" and s2[1] == "#":
        return True
    
    return False


if main():
    print("Yes")
else:
    print("No")
