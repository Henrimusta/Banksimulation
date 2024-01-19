const express = require('express');
const router = express.Router();
const balance = require('../models/balance_model');

router.get('/balance/:id',
    function(request, response){
      console.log(`balance: ${request.params.date}`)
    balance.getbalance(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult);
        }
    })
}
);
router.get('/fname/:id',
    function(request, response){
    balance.getfname(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.send(dbResult);
        }
    })
}
);
router.get('/historyt/:cardID/:startingPoint',
    function(request, response){
    balance.gethistoryt(request.params.cardID,request.params.startingPoint, function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult);
        }
    })
});
router.get('/cardInfo/:id',
    function(request,response){
        balance.getcardInfo(request.params.id,function(err,dbResult){
            if(err){
                response.json(err.errno);
            }
            else{
                console.log(dbResult);
                response.json(dbResult[0]);
            }
        })
    
    
});
router.post('/withdraw', 
function(request, response) {
  balance.withdraw(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
})
  });
router.get('/accountInfo/:id',
    function(request, response){
    balance.getaccountInfo(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult[0]);
        }
    }) 
        
 
});
module.exports = router;