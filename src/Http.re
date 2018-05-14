module IncomingMessage: {
  type t;
  let on: (t, [ | `_end(unit => unit) | `data(Buffer.t => unit)]) => unit;
} = {
  type t;
  [@bs.send]
  external on :
    (t, [@bs.string] [ | [@bs.as "end"] `_end(unit => unit) | `data(Buffer.t => unit)]) =>
    unit =
    "on";
};

module Client: {type t; let get: (string, IncomingMessage.t => unit) => unit;} = {
  type t;
  [@bs.module "http"]
  external get : (string, IncomingMessage.t => unit) => unit = "get";
};