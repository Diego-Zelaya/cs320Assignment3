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
    for i in str:gmatch("[0-9+-/*(%a+)]") do
        StringSplit[#StringSplit+1] = i
    end

    local stack = {}
    local output = {}

    -- main loop
    local mainCount = 0
    for p,q in pairs(StringSplit) do
    mainCount = mainCount + 1

        -- check if String Split in the the table operators
        if not Operators[q] then
            -- q is a operand and add to output table
            output[#output+1] = q
        elseif q  ~= OperatorLParen and q ~= OperatorRParen then

            local current_prec = Precedence[q]
            local is_left_assoc = q ~= LeftAssociative

            local i = 0
            while table.getn(stack) ~= 0 do

                local top_value = stack[table.getn(stack)]
                local top_prec = Precedence[top_value]

                if is_left_assoc == true and current_prec <= top_prec or is_left_assoc == false and current_prec < top_prec then
                    table.remove(stack)
                    output[#output+1] = top_value
                else
                    break
                end -- end if

                i = i + 1
            end -- end of while

            stack[#stack+1] = q

        elseif q == OperatorLParen then
          stack[#stack+1] = q
        else

            local found = false
            local r = 0
            while r ~= table.getn(stack) do

                local top_value = table.remove(stack)
                if top_value == OperatorLParen then
                    found = true
                    break
                end -- end if

                output[#output+1] = top_value
                r = r + 1

            end -- end while

          if found == false then
            print("Parenthesis do NOT match 1.")
          end -- end if

        end -- end of if

    end -- end main for loop

      if stack and stack[table.getn(stack)] == OperatorLParen and OperatorRParen then
        print("Parenthesis do NOT match 2.")
      end

    -- clean the stack
    while table.getn(stack) ~= 0 do
        q = table.remove(stack)
        output[#output+1] = q
    end

    local StringOutPut = table.concat( output, " " )

   return StringOutPut
end -- InFixToPostFix

-- print(InfixToPostfix('3 + 3'))
