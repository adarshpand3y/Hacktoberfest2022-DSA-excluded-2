def allPossibleSubstrings(s, i, idx):
    if(idx == len(s)):
        print(i)
        return
    allPossibleSubstrings(s, i+s[idx], idx+1)
    allPossibleSubstrings(s, i, idx+1)
s = input()
allPossibleSubstrings(s, "", 0)
