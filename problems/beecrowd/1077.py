def main():
    # Time Complexity:  O(N), N is the length of the expression
    # Space Complexity: O(N)
    def iterative_infix_to_postfix(infix: str) -> str:
        stack, postfix = [], ''
        precedence = {'^': 2, '*': 1, '/': 1, '+': 0, '-': 0}
        for i in infix:
            if i.isalnum():
                postfix += i
            elif i == '(':
                stack.append(i)
            elif i == ')':
                while stack[-1] != '(':    # until reaching '('
                    postfix += stack.pop() # pop and append all operators that are on top of the stack
                stack.pop()                # pop remaining '('
            else:
                # pop and append all operators with higher precedence than 'i'
                while stack and stack[-1] != '(' and precedence[stack[-1]] >= precedence[i]:
                    postfix += stack.pop()
                stack.append(i)            # append current operator 'i'
        postfix += ''.join(stack[::-1])    # pop and append all remaining operators
        return postfix

    for _ in range(int(input())):
        infix = input()
        print(iterative_infix_to_postfix(infix))

main()
