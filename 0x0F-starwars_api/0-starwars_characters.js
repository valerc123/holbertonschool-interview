#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;
request(url, (error, res, body) => {
  if (!error) {
    const characters = JSON.parse(body).characters;
    requestCharacter(characters, 0);
  }
});
function requestCharacter (url, index) {
  request(url[index], (err, res, body) => {
    if (!err) {
      console.log(JSON.parse(body).name);
      if (index + 1 < url.length) requestCharacter(url, ++index);
    }
  });
}
