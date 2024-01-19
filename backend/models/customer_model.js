const db = require('../database');

const customer = {
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  getById: function(user, callback) {
    return db.query('select * from customer where idcustomer=?', [user], callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (idCustomer,FName,LName,Contact) values(?,?,?,?)',
      [customer.idCustomer, customer.FName, customer.LName, customer.Contact],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where idcustomer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set FName=?,LName=?, Contact=? where idcustomer=?',
      [customer.FName, customer.LName, customer.Contact, id],
      callback
    );
  }
};
module.exports = customer;