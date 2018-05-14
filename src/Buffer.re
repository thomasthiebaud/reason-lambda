type t;
[@bs.send] external toString : t => string = "toString";
[@bs.send] external concatList : list(t) => t = "concat";
[@bs.send] external concatArray : array(t) => t = "concat";