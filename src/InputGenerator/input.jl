const MAX_WEIGHT = 30
const MAX_VALUE = 300

function main(ARGS)

    if (length(ARGS) < 2)
        throw("É necessário 1 parâmetro. SYNTAX: julia input.jl <número de itens> <capacidade da mochila>")
    end

    local nitems = parse(Int64, ARGS[1])
    local capacity = parse(Int64, ARGS[2])

    mkpath("$(@__DIR__)/../../data/output/n-$(nitems)x$(capacity)/")
    mkpath("$(@__DIR__)/../../data/input/n-$(nitems)x$(capacity)/")
    local file = open("$(@__DIR__)/../../data/input/n-$(nitems)x$(capacity)/instance-n-$(nitems)x$(capacity).in", "w")

    write(file, "$(nitems) $(capacity)\n\n")

    for j = 1:nitems
        local randomWeight = 0
        local randomValue = 0
        randomWeight = rand(1:MAX_WEIGHT)
        randomValue = rand(1:MAX_VALUE)

        write(file, "$(j) $(randomWeight) $(randomValue)\n")
    end

end


main(ARGS)