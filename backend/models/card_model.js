const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const card = {
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  getById: function(user, callback) {
    return db.query('select * from card where sessionUser=?', [user], callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.Pin, saltRounds, function(err, Hashed_Pin) {
    return db.query('insert into card (idCard,ExpireDate,CardNumber,Pin,Account_idAccount,Customer_idCustomer) values (?,?,?,?,?,?)',
      [card.idCard, card.ExpireDate, card.CardNumber, Hashed_Pin, card.Account_idAccount, card.Customer_idCustomer],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where idcard=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.password, saltRounds, function(err, Hashed_Pin) {
      return db.query('update card set (ExpireDate?CardNumber?,Pin?,Account_idAccount?,Customer_idCustomer?) where idCard=?'),
        [card.ExpireDate, card.CardNumber, Hashed_Pin, card.Account_idAccount, card.Customer_idCustomer,id],
        callback
      });
    },
};
module.exports = card;