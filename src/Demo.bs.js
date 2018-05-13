// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Json = require("@glennsl/bs-json/src/Json.bs.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var Http$ReasonLambda = require("./Http.bs.js");

function test(json) {
  return /* record */[
          /* userId */Json_decode.field("userId", Json_decode.$$int, json),
          /* id */Json_decode.field("id", Json_decode.$$int, json),
          /* title */Json_decode.field("title", Json_decode.string, json),
          /* body */Json_decode.field("body", Json_decode.string, json)
        ];
}

var Decode = /* module */[/* test */test];

function handler($$event, _, callback) {
  console.log("Hello, BuckleScript and Reason!" + $$event.name);
  return Curry._2(Http$ReasonLambda.Client[/* get */0], "https://play.google.com/log?format=json", (function (response) {
                Curry._3(Http$ReasonLambda.IncomingMessage[/* onString */0], response, /* Data */758940234, (function (data) {
                        console.log(data);
                        return /* () */0;
                      }));
                Curry._1(callback, Js_exn.raiseError("WAZAAA"));
                return Curry._1(callback, null);
              }));
}

Curry._2(Http$ReasonLambda.Client[/* get */0], "http://jsonplaceholder.typicode.com/posts/1", (function (response) {
        return Curry._3(Http$ReasonLambda.IncomingMessage[/* onBuffer */1], response, /* Data */758940234, (function (data) {
                      console.log(data.toString());
                      var decodedTest = test(Json.parseOrRaise(data.toString()));
                      console.log(decodedTest);
                      return /* () */0;
                    }));
      }));

exports.Decode = Decode;
exports.handler = handler;
/*  Not a pure module */