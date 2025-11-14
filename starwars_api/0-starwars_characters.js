#!/usr/bin/node
const request = require('request');
const args = process.argv.slice(2);
const urlWithInput = 'https://swapi-api.hbtn.io/api/films/' + args[0];

const options = {
  method: 'GET',
  url: urlWithInput
};

function getNameForThisCharacter (url) {
  const optionsBis = {
    method: 'GET',
    url: url
  };

  let promise = new Promise(function (resolve, reject) {
    try {
      request(optionsBis, function (error, response, body) {
        if (!error) {
          const resJSON = JSON.parse(body);
          const result = resJSON.name;
          resolve(result);
        }
      });
    } catch (error) {
      reject(error);
    }
  });
  return promise;
}

async function processCharacters (arrCharactersURL) {
  const numCharacters = arrCharactersURL.length;
  for (let i = 0; i < numCharacters; i++) {
    let url = arrCharactersURL[i];
    try {
      let name = await getNameForThisCharacter(url);
      console.log(name);
    } catch (error) {
      console.error('Error from await function:', error);
    }
  }
}

try {
  request(options, function (error, response, body) {
    if (!error) {
      const bodyJSON = JSON.parse(body);

      const arrCharactersURL = bodyJSON.characters;

      processCharacters(arrCharactersURL);
    }
  });
} catch (err) {
  console.error('Error in request:', err);
}
