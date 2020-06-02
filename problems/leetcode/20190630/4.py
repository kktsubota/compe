class Tree(object):
    def __init__(self, value=None):
        self.value = value
        self.left = None
        self.right = None


noun = {'t', 'f'}
verb_single = {'!'}
verb_double = {'|', '&'}


def parse_verb_single(exp):
    depth = 0
    for s in exp:
        if s == '(':
            depth += 1
        elif s == ')':
            if depth == 1:
                break


def parse(exp):
    if exp in noun:
        return Tree(noun)
    
    elif exp[0] == verb_single:
        tree = Tree()
        depth = 0
        for i in range(len(exp)):
            s = exp[i]
            if i == 0:
                tree.value = s
                continue

            if s == '(':
                depth += 1
            elif s == ')':
                depth -= 1
            if depth == 0:
                tree.left = parse(exp[2:i])


    elif exp == verb_double:
        tree = Tree()

        
def main(exp):
    tree = Tree(None)
    depth = 0
    for s in exp:
        if s in verb_single:

            if s == '(':
                continue            
            tree.left += s
            if s == ',':
                tree.right += s
            if s == ')':
                break


exp = input()
