const db = require('../database');
const dotenv = require('dotenv');

const login = {
    checkPassword:function(cardNumber, callback){
        return db.query('select Pin from card where cardNumber=?', cardNumber, callback);
    }

}

module.exports = login;