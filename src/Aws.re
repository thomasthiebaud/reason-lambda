type snsMessageAttributes = Js.t({.});

type snsMessage = {
  .
  "_SignatureVersion": string,
  "_Timestamp": string,
  "_Signature": string,
  "_SigningCertUrl": string,
  "_MessageId": string,
  "_Message": string,
  "_MessageAttributes": snsMessageAttributes,
  "_Type": string,
  "_UnsubscribeUrl": string,
  "_TopicArn": string,
  "_Subject": string,
};

type record = {
  .
  "_EventVersion": string,
  "_EventSubscriptionArn": string,
  "_EventSource": string,
  "_Sns": snsMessage,
};

[@bs.deriving abstract] type snsEvent = {
    name: string,
};

type callback = Js.Nullable.t(Js.Exn.t) => unit;