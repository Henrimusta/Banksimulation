const express = require('express');
const account = require('../models/account_model');
const router = express.Router();
const Account = require('../models/account_model');

router.get('/',function(request,response){
    account.getAll(function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })
    });

    router.get('/:id',
    function (request, response) {
        Account.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });


router.post('/', 
function(request, response) {
  Account.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      //response.json(dbResult);
      response.json(dbResult.affectedRows);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  Account.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});


router.put('/:update', 
function(request, response) { 
  console.log("Tässää ollaa ekas updates")
  Account.update(request.body.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});

router.put('/:updateAccount', 
function(request, response) {
  console.log("Tässää ollaa tokas updates")
  Account.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});

module.exports = router;

module.exports=router;
