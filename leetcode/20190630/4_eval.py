# class Tree(object):
#     def __init__(self, value):
#         self.value = value
#         self.left = None
#         self.right = None


# noun = {'t', 'f'}
# verb_single = {'!'}
# verb_double = {'|', '&'}


# def parse_verb_single(exp):
#     depth = 0
#     for s in exp:
#         if s == '(':
#             depth += 1
#         elif s == ')':
#             if depth == 1:
#                 break


# def main(exp):
#     depth = 0
#     for s in exp:
#         if s in verb_single:

#             if s == '(':
#                 continue            
#             tree.left += s
#             if s == ',':
#             tree.right += s
#             if s == ')':
#                 break


def calc_not(tf):
    return not tf


def calc_and(*tfs):
    ret = True
    for tf in tfs:
        ret = ret and tf
    return ret


def calc_or(*tfs):
    ret = False
    for tf in tfs:
        ret = ret or tf
    return ret


exp = input()
exp = exp.replace('t', 'True')
exp = exp.replace('f', 'False')
exp = exp.replace('|', 'calc_or')
exp = exp.replace('&', 'calc_and')
exp = exp.replace('!', 'calc_not')
# print(exp)
# print(eval(exp))