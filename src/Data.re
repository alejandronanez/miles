type airport = {
  id: int,
  name: string,
  city: string,
  country: string,
  iata: string,
  icao: string,
  latitude: float,
  longitude: float,
  altitude: int,
  timezone: string,
  dst: string,
  tz: string,
  kind: string,
  source: string,
};

type airports = Js.Dict.t(airport);

let parseAirportJson = json =>
  Json.Decode.{
    id: field("id", int, json),
    name: field("name", string, json),
    city: field("city", string, json),
    country: field("country", string, json),
    iata: field("iata", string, json),
    icao: field("icao", string, json),
    // Used Json.Decode to avoid naming collisions with `float`
    latitude: field("latitude", Json.Decode.float, json),
    longitude: field("longitude", Json.Decode.float, json),
    altitude: field("altitude", int, json),
    timezone: field("timezone", string, json),
    dst: field("dst", string, json),
    tz: field("tz", string, json),
    kind: field("kind", string, json),
    source: field("source", string, json),
  };

let parseAirportsJson = json => Json.Decode.(dict(parseAirportJson), json);

let fetchAirports = () => {
  Bs_fetch.fetch("/data.json")
  |> Js.Promise.then_(Bs_fetch.Response.text)
  |> Js.Promise.then_(jsonText =>
       jsonText |> Js.Json.parseExn |> parseAirportsJson |> Js.Promise.resolve
     );
};