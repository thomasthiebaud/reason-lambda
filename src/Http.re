module IncomingMessage: {
  type t;
  let onString: (t, [ | `Data], string => unit) => unit;
  let onBuffer: (t, [ | `Data], Buffer.t => unit) => unit;
} = {
  type t;
  [@bs.send]
  external onString :
    (t, [@bs.string] [ | [@bs.as "data"] `Data], string => unit) => unit =
    "on";

  [@bs.send]  
  external onBuffer :
  (t, [@bs.string] [ | [@bs.as "data"] `Data], Buffer.t => unit) => unit =
  "on";
};

module Client: {type t; let get: (string, IncomingMessage.t => unit) => unit;} = {
  type t;
  [@bs.module "http"]
  external get : (string, IncomingMessage.t => unit) => unit = "get";
};