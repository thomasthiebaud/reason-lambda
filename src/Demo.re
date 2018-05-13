type test = {
  userId: int,
  id: int,
  title: string,
  body: string,
};

module Decode = {
  let test = json =>
    Json.Decode.{
      userId: field("userId", int, json),
      id: field("id", int, json),
      title: field("title", string, json),
      body: field("body", string, json),
    };
};

let handler = (event: Aws.snsEvent, _, callback: Aws.callback) => {
  Js.log("Hello, BuckleScript and Reason!" ++ (event |. Aws.name));
  Http.Client.get("https://play.google.com/log?format=json", response => {
    Http.IncomingMessage.onString(response, `Data, data => Js.log(data));
    callback(Js.Nullable.return(Js.Exn.raiseError("WAZAAA")));
    callback(Js.Nullable.null);
  });
};

Http.Client.get("http://jsonplaceholder.typicode.com/posts/1", response =>
  Http.IncomingMessage.onBuffer(
    response,
    `Data,
    data => {
      Js.log(data |> Buffer.toString);
      let decodedTest =
        data |> Buffer.toString |> Json.parseOrRaise |> Decode.test;
      Js.log(decodedTest);
    },
  )
);