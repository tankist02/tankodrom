lines = readlines("test.csv")

global tokens = 0

for l in lines
    #println(l)
    for s in l
        if s == ',' 
            global tokens += 1
        end
    end
    global tokens += 1
end

println(size(lines))
println(tokens)

