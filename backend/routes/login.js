const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.cardNumber && request.body.Pin){
      const user = request.body.cardNumber;
      const pass = request.body.Pin;
      
        login.checkPassword(user, function(err, dbResult) {
          if(err){
            response.json(err.errno);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pass,dbResult[0].Pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ username: user });

                  console.log(token);

                  response.send(token);
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send(false);
    }
  }
);

function generateAccessToken(cardNumber) {
  dotenv.config();
  return jwt.sign(cardNumber, process.env.MY_TOKEN, { expiresIn: '3000s' });
}

module.exports=router;