const { request } = require('express');
const database = require('../database');
global.paivays=0;
const debitBalance= {
    getdebitBalance: function(id,callback){
        return database.query('select idcustomer_customer, Fname, Lname, Contact, AccountNumber, account_debitBalance from customer join account on idcustomer_customer=account.id_customer join Tili on account.id_tili=Tili.id_tili where kortin_tunnus=?',[id], callback);

    },
    getaccountInfo: function(id, callback){
        return database.query('select Fname, Lname, Contact, AccountNumber, account_debitBalance from customer join account on idcustomer_customer=account.id_customer join Tili on account.id_tili=Tili.id_tili where tunnus=?',[id], callback);
    },
    getcardInfo: function(id, callback){
        return database.query('select idcard, Pin_koodi from kortti where idcard=?',[id], callback);
    },
    gethistoryt: function(cardID, startingPoint, callback){
        const startingPointToInt = parseInt(startingPoint);
        return database.query('select Tapahtuma_tyyppi, Rahan_maara, @paivays:=Paivays as tapahtuma from customer join account on idcustomer_customer=account.id_customer join Tili on account.id_tili=Tili.id_tili join tapahtuma on Tili.id_tili=tapahtuma.id_tili where kortin_tunnus=? order by Paivays desc limit ?,10',[cardID,startingPointToInt], callback);
    },
    getFname: function(id, callback){
        return database.query('select Fname from customer where kortin_tunnus=?',[id],callback);
    },
    withdraw: function(procedure_params, callback) {
        return database.query
        ('CALL withdraw (?,-?)',
          [procedure_params.id, procedure_params.summa],
          callback
        );
    }
    

};
module.exports = debitBalance;