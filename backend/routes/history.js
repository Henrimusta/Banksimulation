const express = require('express');
const history = require('../models/history_model');
const router = express.Router();


router.get('/getAll',function(request,response){
  console.log(`getAll:`)
  history.getAll(function(err,dbResult){
    if(err){
      response.json(err);
    }
    else{
      response.json(dbResult);
    }
  })
});

router.get('/getNext/:date',function(request,response){
  console.log(`getNext: ${request.params.date}`)
      history.getNext(request.params.date, function(err,dbResult){
          if(err){
              response.json(err);
          }
          else{
              response.json(dbResult);
          }
      })
});

router.get('/getPrevious/:date',function(request,response){
  console.log(`getPrevious: ${request.params.date}`)
      history.getPrevious(request.params.date, function(err,dbResult){
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
        history.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });


router.post('/add', 
function(request, response) {
  console.log("Tässää ollaa ekas history updates")
  history.add(request.body, function(err, dbResult) {
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
  history.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});


router.put('/:id', 
function(request, response) {
  history.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});

module.exports = router;

module.exports=router;