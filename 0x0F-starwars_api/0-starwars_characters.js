#!/usr/bin/node
//Request API for Star Wars Characters
//const process = require("process");
const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`, function (
	error, response, body) {
	if (error) {
		console.error('error:', error);
		return;
	}
	const chara = [];
	const parsedBody= JSON.parse(body);
	for(let i = 0; i < parsedBody['characters'].length; i++) {
		chara.push(new Promise((resolve, reject) => {
			request(parsedBody['characters'][i], function (error,
				response, body) {
				if (error) {
					reject(error);
				} else {
					resolve(parsedBody['name']);
				}
			})
		}))
	};
	Promise.all(characters).then((chars) => {
		for (let ch of chars) {
			console.log(ch);
		}
	});
});
