const fs = require('fs');
const { USERNAME, API_KEY } = require('../../config.json');
var plotly = require('plotly')(USERNAME, API_KEY);
const TAM = 3;
const N = ["n-30x50", "n-30x100", "n-30x10000"];

var b_data = [];
var r_data = [];
var i_data = [];


// Branch and bound
b_data.push({
    valor: 1356,
    itens: [20, 9, 8, 6, ,4, 3],
    tempo: 685
});

b_data.push({
    valor: 2246,
    itens: [29, 28, 25, 21, 20, 18, 15, 8, 5],
    tempo: 385
});

b_data.push({
    valor: 3934,
    itens: [30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
    tempo: 25
});

// Recursive
r_data.push({
    valor: 1356,
    itens: [20, 9, 8, 6, ,4, 3],
    tempo: 21
});

r_data.push({
    valor: 2246,
    itens: [29, 28, 25, 21, 20, 18, 15, 8, 5],
    tempo: 51
});

r_data.push({
    valor: 3934,
    itens: [30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
    tempo: 93
});

// Ierative
i_data.push({
    valor: 1356,
    itens: [20, 9, 8, 6, ,4, 3],
    tempo: 16
});

i_data.push({
    valor: 2246,
    itens: [29, 28, 25, 21, 20, 18, 15, 8, 5],
    tempo: 30
});

i_data.push({
    valor: 3934,
    itens: [30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
    tempo: 2987
});

// Branch and Bound
var bb = {
    x: N,
    y: [b_data[0].tempo, b_data[1].tempo, b_data[2].tempo],
    type: "scatter"
};
var data = [bb];
var layout = {
    title: "Branch and Bound",
    fileopt : "overwrite", 
    filename : "bb_graph",
    xaxis: {
        title: "Instância"
    },
    yaxis: {
        title: "Tempo (microsec)"
    },
    font: {
        size: 20,
    }
};
var graphOptions = {layout: layout, filename: "bb_graph", fileopt: "overwrite"};
plotly.plot(data, graphOptions, function (err, msg) {
    if (err) return console.log(err);
    console.log(msg);
});

// Recursive
var rec = {
    x: N,
    y: [r_data[0].tempo, r_data[1].tempo, r_data[2].tempo],
    type: "scatter"
};
var data = [rec];
var layout = {
    title: "DPR",
    fileopt : "overwrite", 
    filename : "recursive_graph",
    xaxis: {
        title: "Instância"
    },
    yaxis: {
        title: "Tempo (microsec)"
    },
    font: {
        size: 20,
    }
};
var graphOptions = {layout: layout, filename: "recursive_graph", fileopt: "overwrite"};
plotly.plot(data, graphOptions, function (err, msg) {
    if (err) return console.log(err);
    console.log(msg);
});

// Iterative
var it = {
    x: N,
    y: [i_data[0].tempo, i_data[1].tempo, i_data[2].tempo],
    type: "scatter"
};
var data = [it];
var layout = {
    title: "DPI",
    fileopt : "overwrite", 
    filename : "iterative_graph",
    xaxis: {
        title: "Instância"
    },
    yaxis: {
        title: "Tempo (microsec)"
    },
    font: {
        size: 20,
    }
};
var graphOptions = {layout: layout, filename: "iterative_graph", fileopt: "overwrite"};
plotly.plot(data, graphOptions, function (err, msg) {
    if (err) return console.log(err);
    console.log(msg);
});


// COMPARACAO GERAL
var layoutGeral = {
    title: "Comparação",
    fileopt : "overwrite", 
    filename : "comparisonGraph",
    xaxis: {
        title: {
            text: "Instancia"
        }
    },
    yaxis: {
        title: {
            text: "Tempo (microsec)"
        }
    },
    font: {
        size: 20,
    }
};

bb.name = "Branch and Bound";
rec.name = "DPR";
it.name = "DPI";

var comparisonGraph = [bb, rec, it];

var graphOptions = {layout: layoutGeral, filename: "comparisonGraph", fileopt: "overwrite"};
plotly.plot(comparisonGraph, graphOptions, (err, msg) => {
	if (err) return console.log(err);
	console.log(msg);
});

