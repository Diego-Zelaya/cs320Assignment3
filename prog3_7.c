-- function to search for a item in a list
function Set (list)
    local set = {}
    for key,value in ipairs(list) do
      set[value] = true
    end
    return set
end

-- function get table lenth
function table.getn(table)
    local count = 0
    for k,v in pairs(table) do
        -- print(k)
        count = k
    end
  return count
end

-- function that is called from C++ main
function InfixToPostfix(str)

   -- print(str)

    -- operand vars
    local OperatorMultiply = '*'
    local OperatorDivide = '/'
    local OperatorAdd = '+'
    local OperatorSubtract = '-'
    local OperatorLParen = '('
    local OperatorRParen = ')'

    -- list of operators to search
    local Operators = Set {
        OperatorMultiply,
        OperatorDivide,
        OperatorAdd,
        OperatorSubtract,
        OperatorLParen,
        OperatorRParen,
    }

    local LeftAssociative = {
        OperatorMultiply,
        OperatorDivide,
        OperatorAdd,
        OperatorSubtract,
        OperatorLParen,
        OperatorRParen,
    }

    -- list to set precedence
    local Precedence = {
        ['*'] = 7,
        ['/'] = 7,
        ['+'] = 5,
        ['-'] = 5,
        ['('] = 1,
        [')'] = 1,
    }

    -- Split string
    local StringSplit = {}
    for i in str:gmatch("[\\s0-9+-/*]+") do
        StringSplit[#StringSplit+1] = i
    end

    local stack = {}
    local output = {}

    -- main loop
    
    
    OPERATORS = "+-*/()"
PRIORITY = {'(' : -1, '+' : 0, '-' : 0, '*' : 1, '/' : 1}
def infixToPostfix(infixExp):
    s = Stack()
    postfixExp = ""
    for ch in infixExp:
        if ch >= 'a' and ch <= 'z':
            postfixExp += ch
        elif ch in OPERATORS:
            if s.empty():
                s.push(ch)
            else:
                if ch == ')':
                    while (not s.empty()) and (s.top() != '('):
                        postfixExp += s.pop()
                    s.pop()
                elif ch == '(':
                    s.push(ch)
                else:
                    while not s.empty() and PRIORITY[s.top()] >= PRIORITY[ch]:
                        postfixExp += s.pop()
                    s.push(ch)
    while not s.empty():
        postfixExp += s.pop()
    return postfixExp

def calculate(postfixExp, varDic):
    s = Stack()
    for ch in postfixExp:
        if ch >= 'a' and ch <= 'z':
            s.push(int(varDic[ch]))
        else:
            r = s.pop()
            l = s.pop()
            res = 0
            if   ch == '+':
                res = l + r
            elif ch == '-':
                res = l - r
            elif ch == '*':
                res = l * r
            elif ch == '/':
                res = l / r
            s.push(res)
    return s.pop()

infixExp = raw_input("Enter a infix experssion:")
if len(infixExp) == 0: infixExp = "a + b * c + (d * e + f) * g"
postfixExp = infixToPostfix(infixExp)
print postfixExp

valStr = raw_input("Enter the values of the variables:")
if len(valStr) == 0:
    valStr = "a=1,b=2,c=3,d=4,e=5,f=6,g=7"
valDic = eval("dict(%s)" % valStr)
print calculate(postfixExp, valDic)
    
    
    end -- end main for loop

      if stack and stack[table.getn(stack)] == OperatorLParen and OperatorRParen then
        print("Parenthesis do NOT match.")
      end

    -- clean the stack
    while table.getn(stack) ~= 0 do
        q = table.remove(stack)
        output[#output+1] = q
    end

    local StringOutPut = table.concat( output, " " )

   return StringOutPut
end -- InFixToPostFix

--print(InfixToPostfix('10 * 3'))
