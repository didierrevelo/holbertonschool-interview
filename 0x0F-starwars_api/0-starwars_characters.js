const request = require('request');
const argv = process.argv;
request('https://swapi-api.hbtn.io/api/films/' + argv[2], function (error, response, body) {
  // console.log(JSON.parse(body));
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;

    // console.log(characters);
    characters.forEach(item => (request(item, function (error, response, body) {
      if (error) {
        console.log(error);
      } else {
        console.log(JSON.parse(body).name);
      }
    })));
  }
});