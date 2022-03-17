const request = require('request');
const argv = process.argv;
request('https://swapi-api.hbtn.io/api/films/' + argv[2], function (error, response, body) {
  // console.log(JSON.parse(body));
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    let i = 0;
    // requestCharacter(i, characters);
    requestCharacter2(i, characters);
  }
});

// async function requestCharacter(i, characters) {
//     if (i == characters.length) {
//         return;
//     }
//     let url = characters[i]
//     request(url, function (error, response, body){
//         const didier = JSON.parse(body)
//         console.log(didier.name) 
//         i++;
//         requestCharacter(i, characters)  
//     })
          
// }

async function requestCharacter2(i, characters) {
    if (i == characters.length) {
        return;
    }
    for (i; i < characters.length; i++){
        let url = characters[i]
        request(url, function (error, response, body){
            const didier = JSON.parse(body  )
            console.log(didier.name) 
            // i++;
            // requestCharacter2(i, characters) 
            }) 
    }
}
