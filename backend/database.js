const mysql=require('mysql2');
const dotenv=require('dotenv');

dotenv.config();


const connection=mysql.createPool(process.env.SQL_SERVER);



    /*host: process.env.HOST || "127.0.0.1",
    database: process.env.DATABASE || "bankdatabase",
    user: process.env.USER || "netpass",
    password: process.env.PASSWORD || "netuser",
    supportBigNumbers:true,
    bigNumberStrings: true*/
//});


//const connection=mysql.createPool({
    /*host: process.env.HOST || "127.0.0.1",
    database: process.env.DATABASE || "bankdatabase",
    user: process.env.USER || "netuser",
    password: process.env.PASSWORD || "netpass",
    supportBigNumbers:true,
    bigNumberStrings: true*/
//});

module.exports=connection;