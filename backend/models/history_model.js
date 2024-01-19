const db = require('../database');

const history = {
  getAll: function(callback) {
    return db.query('select idHistory, Amount, DATE_FORMAT(Date,"%Y.%m.%d") as Date from history order by Date desc limit 5', callback);
  },
  getNext: function(date, callback) {
    var ret= db.query('select Amount, DATE_FORMAT(Date,"%Y.%m.%d") as Date from history where Date<=? order by Date desc limit 5', [date], callback);
    return ret;
  },
  getPrevious: function(date, callback) {
    var ret= db.query('select Amount, DATE_FORMAT(Date,"%Y.%m.%d") as Date from history where Date>=? order by Date desc limit 5', [date], callback);
    return ret;
  },
  getById: function(id, callback) {
    return db.query('select * from history where idHistory=?', [id], callback);
  },
  add: function(history, callback) {
    return db.query(
 jyri
      'insert into history (Date,Amount) values(?,?)',
      [history.Date, history.Amount],

      'insert into history (Date, Amount,Account_idAccount) values(?,?,?)',
      [history.Date, history.Amount, history.Account_idAccount],
 main
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from history where idHistory=?', [id], callback);
  },
  update: function(id, history, callback) {
    return db.query(
      'update history set Date=?,Amount=?, Account_idAccount=? where idHistory=?',
      [history.Date, history.Amount, history.Account_idAccount, id],
      callback
    );
  }
};
module.exports = history;