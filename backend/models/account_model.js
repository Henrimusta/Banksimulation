const db = require('../database');

const account = {
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from account where idaccount=?', [id], callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (idAccount,AccountNumber,DebitBalance,CreditBalance) values(?,?,?,?)',
      [account.idAccount, account.AccountNumber, account.DebitBalance, account.CreditBalance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where idaccount=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set AccountNumber=?,DebitBalance=?, CreditBalance=? where AccountNumber=?',
      [account.AccountNumber, account.DebitBalance, account.CreditBalance, account.AccountNumber,],
      callback
    );
  }
};
module.exports = account;